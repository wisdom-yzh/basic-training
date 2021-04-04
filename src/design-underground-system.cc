#include <string>
#include <unordered_map>
#include <vector>
#include <tuple>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<string, pair<double, int>> schedule;
    unordered_map<int, pair<string, int>> checkInRecord;

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkInRecord[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        const auto &iter = checkInRecord.find(id);
        auto &fromStation = iter->second.first;
        auto &fromTime = iter->second.second;
        const auto &record = schedule.find(fromStation + " " + stationName);

        if (record == schedule.end()) {
            schedule.insert({ fromStation + " " + stationName, { t - fromTime, 1 }});
        } else {
            record->second.first += t - fromTime;
            record->second.second++;
        }
    }

    double getAverageTime(string startStation, string endStation) {
        const auto &iter = schedule.find(startStation + " " + endStation);
        return iter->second.first / iter->second.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 */
int main() {
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    undergroundSystem.getAverageTime("Paradise", "Cambridge");
    undergroundSystem.getAverageTime("Leyton", "Waterloo");
    undergroundSystem.checkIn(10, "Leyton", 24);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");
    undergroundSystem.checkOut(10, "Waterloo", 38);
    undergroundSystem.getAverageTime("Leyton", "Waterloo");
    return 0;
}

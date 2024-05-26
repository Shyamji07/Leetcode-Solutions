class MyCalendarTwo {
public:
    bool book(int start, int end) {
        for (const auto& pair : doubleBooked){
            if (pair.first < end && pair.second > start)
                return false; // if triple booked return false
        }
        for (const auto& pair : events){
            if (pair.first < end && pair.second > start) // double booked
                doubleBooked.push_back({max(pair.first, start), min(pair.second, end)});
        }
        events.push_back({start, end}); // add new event
        return true;
    }
    
private:
    vector<pair<int, int>> events; // all events
    vector<pair<int, int>> doubleBooked; // double booked events
};
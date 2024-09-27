class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleOverlapBooking;
    vector<pair<int, int>> overallBookings;

    bool checkOverlap(int start1, int end1, int start2, int end2){
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> overlapRegion(int start1, int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {

        //Check if triple booking is being created or not
        for(pair<int, int> region : doubleOverlapBooking){
            if(checkOverlap(region.first, region.second, start, end))
                return false;       //triple booking created
        }

        //Check if double booking is being created or not
        for(pair<int, int> booking : overallBookings){
            if(checkOverlap(booking.first, booking.second, start, end))
                doubleOverlapBooking.push_back(overlapRegion(booking.first, booking.second, start, end));
        }

        overallBookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
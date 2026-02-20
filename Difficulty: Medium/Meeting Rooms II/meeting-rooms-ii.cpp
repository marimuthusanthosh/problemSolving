class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
       sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0;
        int rooms = 0, maxRooms = 0;
        
        while(i < start.size() && j < end.size()) {
            if(start[i] < end[j]) {
                // A new meeting starts before the earliest one ends
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                // A meeting ended, free up a room
                rooms--;
                j++;
            }
        }
        return maxRooms;
        
    }
};

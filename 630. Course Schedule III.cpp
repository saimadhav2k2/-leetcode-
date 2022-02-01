class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), [&](auto course1, auto course2) {
            return course1[1] < course2[1];
        });
            
        priority_queue<int> taken;
        int totalDuration = 0;
        
        for(auto course: courses) {
            int duration = course[0];
            int deadline = course[1];
            
            taken.push(duration);
            
            totalDuration += duration;
            
            if(totalDuration > deadline) {
                totalDuration -= taken.top();
                taken.pop();
            }
        }
        
        return taken.size();
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int lp = 0;
        int rp = n-1;
        int maxwater = 0;

        while(lp <= rp){
            int ht = min(height[lp], height[rp]);
            int width = rp - lp;
            int current_area = ht * width;

            maxwater = max(maxwater, current_area);

            if(height[lp] < height[rp]){
                lp++;
            }else{
                rp--;
            }
        }
        return maxwater;
    }
};
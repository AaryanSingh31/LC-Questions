class MedianFinder {
public:
    priority_queue<int> maxHeap; //to get the largest number in the lefthalf
    priority_queue<int, vector<int>, greater<int>> minHeap; //to get the largest number in the right half
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()){ //if new number is smaller than top of left half then push it into the left half ie, maxHeap side
            maxHeap.push(num);
        }else {
            minHeap.push(num); //else push it to the right side ie, minHeap
        }
        //SIZE BALANCING ->  //Maxheap ka size minheap ke size se ek se jyada bada ni hona chahiye if dono ke size same honge toh hi toh hme middle element milega dono ke top ka jo ki medain hoga

        //MAx heap ya toh barabar hoga ya sirf ek bada hoga
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top()); //left part ka sabse bada number right part mein daal do so that maxHeap and minHeap boundary can be shift 1 by right
            maxHeap.pop();
        }
        //Min heap ka size barabar ya ek chhota ho skta h but bada nhi ho skta
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top()); //agar hogya toh sabse chhota element min heap(right side ka) left part (max heap) mein bhej do.. ie, maxHeap and minHeap dono ki boundary ko left shift kardo by 1.
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){ //if dono ka size same that means even numbers hain total so.. dono ke top elements hi medain honge.. toh uska avg leliya
            return (minHeap.top() + maxHeap.top())/2.0;
        } 
        return maxHeap.top(); //agar maxHeap ka size ek bada h toh numbers odd hain aur us case mein maxHeap ka top hi median element hoga
    }     
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
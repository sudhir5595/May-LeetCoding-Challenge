class StockSpanner {
public:
    int n = 0;
    stack <int> price_stack;
    stack <int> weight;
    StockSpanner() {
        // price_stack = new stack;
        // weight = new stack;
    }
    
    int next(int price) {
        int w = 1;
            while(price_stack.size() != 0 && price >= price_stack.top()){
                price_stack.pop();
                w += weight.top();
                weight.pop();
            }
            price_stack.push(price);
            weight.push(w);
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

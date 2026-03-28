You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// algorithm designing
// this one i think should like search for all revenue pattern here and update the max value for each pattern.

/* 

1. generate the different graph from element for all combination start from 7
2. from path hop 1, path hop 2, path hop3, however if the path is negative then dont establisth the path
3. once form the graph traverse all of graph, downword, where each node is treated as root (have chance)
4. then save the traverse path as mx
5. then return max

*/

// algorithm designing
// seems like im overly complicated the prob :P 
// 
// we can just take every positive clib as sum then ok
// 

// wrong thinking !!!
/*

“Wait, if I sell too early at 2, maybe I lose the chance to hold until 5.”

That would be a problem if selling prevented buying again immediately.

But the problem allows:

sell today
buy again on the same day

and you can do multiple transactions, as long as you hold at most one stock at a time.

So selling at 2 does not destroy the future opportunity.

In fact:

buy at 1, sell at 2 → profit 1
buy at 2, sell at 5 → profit 3

Total = 4

This is exactly same as just holding from 1 to 5.











This problem works because you are allowed to make unlimited transactions, you can only hold one stock at a time, and you can sell and buy again immediately without any cost or restriction. Under these conditions, the maximum profit can be obtained by simply taking every increase in price between consecutive days.

The key idea is that any overall increase in price can be broken into smaller increases without changing the total profit. For example, if the price goes from 1 to 5 to 99, buying at 1 and selling at 99 gives a profit of 98. If you instead split it into two trades, buying at 1 and selling at 5 gives 4, then buying again at 5 and selling at 99 gives 94, and the total is still 98.

You can visualize it like this:

1 -------- 5 -------- 99

Single trade:

buy 1 -------------------------- sell 99
profit = 99 - 1 = 98

Split trades:

buy 1 -------- sell 5      buy 5 -------- sell 99
       +4                         +94

Now expand the math to see what happens in the middle:

(5 - 1) + (99 - 5)
= 5 - 1 + 99 - 5
= 99 - 1 + (-5 + 5)

Highlight the key part:

-5 + 5 = 0   ← cancels out

So it becomes:

= 99 - 1
= 98

This shows that the “buy at 5 and sell at 5” effect cancels out completely, meaning splitting the trade does not lose anything. Selling early does not remove your ability to continue the profit, because you can immediately buy again at the same price.

Because of this property, instead of trying to find optimal buy and sell points, you can simply add every positive difference between consecutive days. This guarantees the maximum profit.

This approach would not work if there were additional constraints such as transaction fees, cooldown periods, or limits on the number of trades, because in those cases splitting transactions would introduce extra cost or restrict future actions.


int maxProfit(vector<int>& prices) {
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}
*/
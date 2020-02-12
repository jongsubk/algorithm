#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Structure
struct contextElement
{
  string context;
  float x;
};

  //auto comp1 = [] ( const contextElement& lhs, const contextElement& rhs ) {return lhs.context == rhs.context;};
  bool comp1 ( const contextElement& lhs, const contextElement& rhs ) {
      return lhs.context == rhs.context;
  }


    int maxProfit(vector<int>& prices) {
        
        int size = prices.size();
        int sum = 0;
        bool fbought = false;
        for(int i=0; i<size; i++) {
            
            if( i == size-1 ) { //last
                if( fbought ) { sum += prices[i]; }

                cout << " [COOL:" << i;
                break;
            }
            
            if( !fbought && prices[i] < prices[i+1] ) { //tomorrow expensive => BUY
                sum -= prices[i];
                fbought = true;
                
                cout << " [BUY:" << i;
            }
            else if( fbought && ((prices[i]-prices[i-1])<(prices[i+1]-prices[i]) ? 0:1) ) { // SELL
                sum += prices[i];
                fbought = false;
                i++;
                cout << " [SELL:" << i;
            }
        }
        return sum;
        
    }


int main() {

/* remove duplicated elemeent
    vector<int> v = { 1,2,2,2,5,7,7,7,8 };
    vector<int>::iterator itr;

    itr = unique(v.begin(), v.end());
    cout << *itr << "just finish unique";
    v.resize(distance(v.begin(), itr));

    for(itr=v.begin(); itr!=v.end(); itr++) {
        cout << *itr << ", ";
    }
*/

 vector<contextElement> v1;
  v1.push_back({"1",1.0});
  v1.push_back({"2",2.0});
  v1.push_back({"1",1.0});
  v1.push_back({"1",1.0});
  //sort elements@HaniGoc: unique only removes consecutive duplicates. If you want to move all //duplicates, then either sort it first, or do something more complicated. –  Mike Seymour
  //auto comp = [] ( const contextElement& lhs, const contextElement& rhs ) {return lhs.context < rhs.context;};
  //sort(v1.begin(), v1.end(),comp);
    std::sort(v1.begin(), v1.end(), [](contextElement& l, contextElement& r) { return l.x < r.x ; });
    
    vector<contextElement>::iterator itr = unique(v1.begin(), v1.end(), comp1);
    v1.resize( distance(v1.begin(), itr) );
  //vector<contextElement>::iterator last = std::unique(v1.begin(), v1.end());
  //v1.erase(last, v1.end());


    vector<int> v = { 6,1,3,2,4,7 };
    cout << maxProfit(v);

    return 0;
}
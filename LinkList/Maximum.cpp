#include<iostream>
#include <stack>
#include<string>
#include<vector>
using namespace std;



/*
如果存在最大公因子，那么一个字符串一定是另外一个字符串的整数倍，
用栈的方式消掉字符串重复的部分，剩下的部分循环与辅助栈的临时因子
进行比较
 */
/*
首先要判断两个字符串能不能整除
 */



//当开始出现与前一个元素完全相同的字符的时候，开始与辅助栈进行比较，直到最后一个元素仍然完全相同，则认为找到了循环项（最大公因子）

  bool judgement(string str1 , string str2){
   vector<char> temp;
   vector<char> result;

   auto index1 = str1.begin();
   auto index2 = str2.begin();
   char char1 = *index1;
   char char2 = *index2;
   while (*index1 == *str1.end() || *index2 == *str2.end())
   {
   if (char1 == char2)
   {
    temp.emplace_back(char1);
    index1++;
    index2++;

   }
   
   }
   


}

int main(){
    string str1 = "asb";
    string str2 = "asb";
    bool judge =  judgement(str1 , str2);
    cout<<judge<<endl;
    return 0;

}
//如果a字符串加B，字符串等于B字符串加a字符串，则认为AB字符串存在最大公因子。AB长度进行辗转相除，得到的结果即为最大公因子的长度。从a或B取前N长度的字符即为最大公因子。

/*

	class Solution {
	public:
		string gcdOfStrings(string str1, string str2) {
			string s1 = str1 + str2;
			string s2 = str2 + str1;
			if (s1.compare(s2))
				return "";
			string a, b;
			if (str1.size() > str2.size()) {
				a = str1;
				b = str2;
			}
			else {
				a = str2;
				b = str1;
			}
			while (b.size() % a.size() != 0) {
				a = a.substr(b.size() * (a.size() / b.size()));
				string temp = b;
				b = a;
				a = temp;
			}
			return a;
		}

	};
*/
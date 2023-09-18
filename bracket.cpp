
class Solution {
public:
    bool isValid(string s) {

        unordered_map<char , int> bracketMap {{'(' , 1} , {')' , 4} , {'[' , 2} , {']' , 5}
                                          , {'{' , 3} , {'}' , 6}};
        stack<char> bracketStack;
        bool judge = true;       
        for(char bracket : s){
            int flag = bracketMap[bracket];
            //如果是左括号就入栈
            if(flag >=1 && flag <=3){
                bracketStack.push(bracket);
            }

            //如果是右括号就与栈里的元素进行判断
            else if(!bracketStack.empty() && bracketMap[bracketStack.top()] == flag - 3 ){
                bracketStack.pop();
            }

            else{
                judge = false;
                break;
            }

        }                           
        if(!bracketStack.empty()){
            judge = false;
        }
return judge;
    }
};
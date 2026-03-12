class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;  //去除負數的情況
        }
        int m = x;  //先記住原本的x
        long y = 0;  //資料型態要設為long

        while(x != 0){  //透過迴圈和運算將整數反轉並存進y中
            y = y * 10 + x % 10; 
            x /= 10;
        }
        return m==y;
    }
};
#include <regex>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
#include <iostream>



//ამოწმებს რომაული რიცხვის სისწორეს
//source - https://www.geeksforgeeks.org/validating-roman-numerals-using-regular-expression/
bool ValidationOfRomanNumerals(string str)
{
 
    const regex pattern("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
 
    if (str.empty()) {
        return false;
    }
 
    if (regex_match(str, pattern)) {
        return true;
    }
    else {
        return false;
    }
}


int translate_roman_numeral(string input) {              //რომაული რიცხვები, რომელიც წარმოადგენს ტექსტურ მონაცემს გადაყავს ინტეჯერის ფორმატში
    map<char, int> roman_numerals = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int output = 0; 
    for (int i = 0; i < input.length(); i++) {
        if (i > 0 && roman_numerals[input[i]] > roman_numerals[input[i-1]]) {
            output += roman_numerals[input[i]] - 2 * roman_numerals[input[i-1]];
        } else {
            output += roman_numerals[input[i]];  
        }
    }
    return output;
}

string int_to_roman(int num) {            //აღნიშნულ ფუნქცია არაბული რიცხვებს აკონვერტირებს რომაულში
    string roman = "";                    
    // if (num>=4000) {                   // გათვალისწინებულია ისიც, რომ რომაული რიცხვის დიაპაზონია 1-3999-მდე, თუმცა დაკომენტარებულია ფუნქციაში ეს კონრკეტული შეზღუდვა, რადგან კონკრეტულად ჩვენს დავალებაში არ იყო საჭირო
    //     return "Number is too larg to convert into Roman numerals"; 
    // }
    while (num >= 1000) {
        roman += "M";
        num -= 1000;
    }
    while (num >= 900) {
        roman += "CM";
        num -= 900;
    }
    while (num >= 500) {
        roman += "D";
        num -= 500;
    }
    while (num >= 400) {
        roman += "CD";
        num -= 400;
    }
    while (num >= 100) {
        roman += "C";
        num -= 100;
    }
    while (num >= 90) {
        roman += "XC";
        num -= 90;
    }
    while (num >= 50) {
        roman += "L";
        num -= 50;
    }
    while (num >= 40) {
        roman += "XL";
        num -= 40;
    }
    while (num >= 10) {
        roman += "X";
        num -= 10;
    }
    while (num >= 9) {
        roman += "IX";
        num -= 9;
    }
    while (num >= 5) {
        roman += "V";
        num -= 5;
    }
    while (num >= 4) {
        roman += "IV";
        num -= 4;
    }
    while (num >= 1) {
        roman += "I";
        num -= 1;
    }
    return roman;
}



int main() {
    int num1, num2, result;
    string str1, str2;
    string operation;
    cout << "Enter number: ";
    cin >> str1;
    while (!ValidationOfRomanNumerals(str1)) {           //while უზრუნველყოფს უწყვეტ რეჟიმში მოთხოვნას სწორი მონაცემისას, რადგან შეიძლება მომხმარებელმა რამდენჯერმე არასწორად შეიყვანოს მონაცემი
        if (str1=="exit") {                              
            return 0;
        }
        cout << "Enter correct Roman numeral:  ";
        cin >> str1;      
    }
    num1=translate_roman_numeral(str1);
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    while (operation!="+"&&operation!="-"&&operation!="*"&&operation!="/"&&operation!="exit"){  //ვინაიდან, შესაძლოა მცდარი სიმბოლო იქნეს შეყვანილი ოპერატორის შეყვანისასაც, შეზღუდულია სხვა სიმბოლოს შეყვანა, რომელიც არ იქნება  მოცემული სიმბოლოებიდან რომელიმეს ტოლი ან თუ არ უდრის exit-ს
        cout<<"Enter valid operation: ";          //აქაც გამოყენებულია while, if-ის ნაცვლად, რადგან შესაძლოა ზედიზედ რამდენჯერმე იქნეს შეყვანილი არასწორი სიმბოლო
        cin>>operation;
    }
    
    while (operation!="exit")
        
    {
        cout << "Enter number: ";
        cin >> str2;
        
        while (!ValidationOfRomanNumerals(str2)) {
        if (str2=="exit") { 
            break;
        }
        cout << "Enter correct Roman numeral:  ";
        cin >> str2;      
    }
        num2=translate_roman_numeral(str2);
       if (operation=="+") {
            result = num1 + num2;}
       if (operation=="-") {
            result = num1 - num2;}
       if (operation=="*") {
            result = num1 * num2;}
       if (operation=="/") {
            result = num1 / num2;}
        
        num1=result;
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        while (operation!="+"&&operation!="-"&&operation!="*"&&operation!="/"&&operation!="exit"){
            cout<<"Enter valid operation: ";
            cin>>operation;
        }
        
    }
     if (num1<=0||num1>=4000){    //ვინაიდან შესაყვანი მონაცემების დიაპაზონი არ შევზღუდეთ 1-100-მდე, საჭირო გახდა აღნიშნული შეზღუდვის დადებაც, რადგან რომაულში არ გვაქ უარყოფითი რიცხვები და ასევე რიცხვები 3999-ს ზემოთ
         cout<<"Result is out of Roman numerals range and is equals to: "<<num1<<endl;
     }  
     else
     cout << "Result: " << int_to_roman(num1) << endl;
        
  
  

    return 0;
}

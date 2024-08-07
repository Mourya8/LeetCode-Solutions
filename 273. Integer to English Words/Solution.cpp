class Solution {
public:
    
string convertToWords(int num) {
string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string hundreds[] = {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};


    if (num == 0)
        return "zero";
    if (num > 999 || num < 0)
        return "Number out of range";

    string result;

    int hundred = num / 100;
    if (hundred > 0) {
        result += hundreds[hundred];
    }

    int remainder = num % 100;
    if (remainder > 0) {
        if (!result.empty()) {
            result += " ";
        }
        if (remainder < 10) {
            result += ones[remainder];
        } else if (remainder > 10 && remainder < 20) {
            result += teens[remainder - 10];
        } else {
            int ten = remainder / 10;
            int one = remainder % 10;
            result += tens[ten];
            if (one > 0) {
                result += " " + ones[one];
            }
        }
    }

    return result;
}
    string numberToWords(int num) {
        if(num==0) return "Zero";
        int b,m,t,n;
        int carry;
        b=num/1000000000;
        carry=num%1000000000;
        m=carry/1000000;
        carry=carry%1000000;
        t=carry/1000;
        carry=carry%1000;
        n = carry;
        string r = "";
        if(b!=0)
        {
            r=r+" "+convertToWords(b)+" Billion";
        }
        if(m!=0)
        {
            r=r+" "+convertToWords(m)+" Million";
        }
        if(t!=0)
        {
            r=r+" "+convertToWords(t)+" Thousand";
        }
        if(n!=0)
        {
            r=r+" "+convertToWords(n);
        }
        return r.substr(1);
    }
};
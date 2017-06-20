12. Integer to Roman
//按照正常解读一个数字的思维即可解决
class Solution {
public:
    string intToRoman(int num) {
        string result;
        int r1, r2, r3, r4;
        if((r1 = num / 1000) > 0){
            switch(r1){
                case 1: result += 'M';
                    break;
                case 2: result += "MM";
                    break;
                case 3: result += "MMM";
                    break;
                default:
                    break;
            }
            num = num - num / 1000 * 1000;
        }
        if((r2 = num / 100) > 0){
            switch(r2){
                case 1: result += 'C';
                    break;
                case 2: result += "CC";
                    break;
                case 3: result += "CCC";
                    break;
                case 4: result += "CD";
                    break;
                case 5: result += "D";
                    break;
                case 6: result += "DC";
                    break;
                case 7: result += "DCC";
                    break;
                case 8: result += "DCCC";
                    break;
                case 9: result += "CM";
                    break;
                default:
                    break;
            }
            num = num - num / 100 * 100;
        }
        if((r3 = num / 10) > 0) {
            switch(r3){
                case 1: result += 'X';
                    break;
                case 2: result += "XX";
                    break;
                case 3: result += "XXX";
                    break;
                case 4: result += "XL";
                    break;
                case 5: result += "L";
                    break;
                case 6: result += "LX";
                    break;
                case 7: result += "LXX";
                    break;
                case 8: result += "LXXX";
                    break;
                case 9: result += "XC";
                    break;
                default:
                    break;
            }
            num = num - num / 10 * 10;
        }
        if((r4 = num) > 0){
            switch(r4){
                case 1: result += 'I';
                    break;
                case 2: result += "II";
                    break;
                case 3: result += "III";
                    break;
                case 4: result += "IV";
                    break;
                case 5: result += "V";
                    break;
                case 6: result += "VI";
                    break;
                case 7: result += "VII";
                    break;
                case 8: result += "VIII";
                    break;
                case 9: result += "IX";
                    break;
                default:
                    break;
            }
        }
        return result;
    }
};

看见这个你怕了吗

public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
package exp1;

import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Scanner;

/**
 * @Author: Song-zy
 * @Date: 2021/10/23 13:03
 * @Description:
 */

public class ThreeWan {
    public static void main(String[] args) {
        String str = null;
        String[] s;
        int count = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        Scanner sc = new Scanner(System.in);
        str = sc.nextLine();
        str = str.replace(" ", "");//将空格删掉
        str = str.toLowerCase();//全部转换为小写字母
        for (int i = 0; i < str.length(); i++) {
            if (!map.containsKey(str.charAt(i))) {
                map.put(str.charAt(i), 1);
            } else {
                map.put(str.charAt(i), map.get(str.charAt(i)) + 1);
            }
        }
        DecimalFormat df = new DecimalFormat("0.00");
        count = str.length();
        for (Character c : map.keySet()) {
            System.out.println(c + "出现的次数为：" + map.get(c));
            System.out.println("\t" + c + "出现的频率为：" + df.format(map.get(c) * 1.0 / count * 100) + "%");
        }
    }
}
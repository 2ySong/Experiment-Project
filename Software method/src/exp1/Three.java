package exp1;

import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author: Song-zy
 * @Date: 2021/10/22 11:35
 * @Description: 程序3：
 * 对于输入的一段英文（也可以读取文件中的英文文本），统计输出26个英文字母（不区分大小写）的出现次数
 * 以及出现概率（出现次数/总字母数），注意，空格不计入统计
 */
public class Three {
    @SuppressWarnings("all")
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入字符串：");
        String str = scanner.nextLine();
        char ch1[] = str.toCharArray();//将输入的字符串转换为字符数组
        int arr[] = new int[26];//每个数组元素是分别记录26个字母出现的个数
        //获取26个子母的次数
        for (int i = 0; i < ch1.length; i++) {
            for (int j = 0, m = 97, n = 65; j < 26; j++) {
                //m小写字母, n大写字母
                if (ch1[i] == m++ || ch1[i] == n++) {
                    arr[j]++;
                }
            }
        }
        System.out.println("+-+-26个字母出现的次数(不区分大小写)-+-+");
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                double probability = (double) arr[i] / ch1.length;
                //格式化概率：保留两位小数，最简便的方法，调用DecimalFormat类。最后的概率就是00.00%格式
                DecimalFormat df = new DecimalFormat("0.00");
                System.out.println((char) (i + 65) + "：" + arr[i] +
                        "次, 概率p=" + df.format(probability * 100) + "% ");
            }
        }
        System.out.println("\n+-+-数组表示-+-+");
        System.out.println(Arrays.toString(arr));
    }
}

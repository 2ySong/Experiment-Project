package exp1;

import java.text.DecimalFormat;

/**
 * @Author: Song-zy
 * @Date: 2021/10/22 8:04
 * @Description:
 * 程序1：
 *      产生100个0~999之间的随机数，判断并输出这些随机数是否为素数，然后计算这100个随机整数中素数的个数和出现频率
 */
public class First {
    public static void main(String[] args) {
        int[] nums = new int[100];
        for (int i = 0; i < nums.length; i++) {
            //Math.random()是令系统随机选取大于等于 0.0 且小于 1.0 的伪随机 double 值
            nums[i] = (int) (Math.random() * 999);//0~999之间的随机数赋值给数组元素
        }
        System.out.println("====随机数组====");
        for (int i = 0; i < nums.length; i++) {
            if (i % 10 == 0 && i != 0) {
                System.out.println();
            }
            System.out.print(nums[i] + " ");
        }
        System.out.println("====数组中的素数====");
        int k = 0;//统计素数的个数
        for (int i = 0; i < 100; i++) {
            if (isPrime(nums[i])) {
                System.out.print(nums[i] + " ");
                k++;
            }
        }
        DecimalFormat df = new DecimalFormat("0.00");
        System.out.println("\n该随机数组中共有" + k + "个素数！, 出现的频率为：" + df.format(k) + "%");
    }

    //判断是否为素数
    @SuppressWarnings("all")//抑制警告
    public static boolean isPrime(int number) {
        if (number < 2) {//若此数小于2，则不是质数
            return false;
        }
        //从1-number本身循环取余计算
        for (int i = 1; i < number; i++) {
            if (number % i == 0) {//余数为0，能整除
                if (number == i) {//是否是本身
                    return true;
                } else if (i != 1) {//是否是1
                    return false;
                }
            }
        }
        return true;
    }
}

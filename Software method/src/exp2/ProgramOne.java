package exp2;

import java.util.*;

/**
 * @Author: Song-zy
 * @Date: 2021/10/28 21:20
 * @Description:
 */
public class ProgramOne {
    @SuppressWarnings("all")
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
        System.out.println();
        LinkedHashSet lht = new LinkedHashSet();
        HashMap<Integer, Integer> hashMap = new HashMap();
        for (int i = 0; i < 100; i++) {
            hashMap.put(nums[i],1);
        }
        for (int i = 0; i < nums.length; i++) {
            boolean found = lht.add(nums[i]);
            if (found == false) {
                hashMap.put(nums[i], hashMap.get(nums[i])+1);
            }
        }
        System.out.println(lht.size());
        Set keySet = hashMap.keySet();
        int k = 0;
        for (Object o :keySet) {
            System.out.print(o+"次数"+hashMap.get(o)+"  ,");
            k++;
            if(k%7==0){
                System.out.println();
            }
        }
    }
}

package exp2;

import java.util.HashMap;
import java.util.Set;

/**
 * @Author: Song-zy
 * @Date: 2021/10/28 22:05
 * @Description: 优化后
 */
public class ProgramOne2 {
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

        HashMap<Integer, Integer> hashMap = new HashMap();
        for (int i = 0; i < nums.length; i++) {
            if (hashMap.get(nums[i]) == null) {
                hashMap.put(nums[i], 1);
            } else {
                hashMap.put(nums[i], hashMap.get(nums[i]) + 1);
            }
        }

        Set keySet = hashMap.keySet();
        for (Object key : keySet) {
            if (hashMap.get(key) != 1)
                System.out.println(key + "出现" + hashMap.get(key) + "次; ");
        }
        System.out.println(hashMap.size());
        System.out.println("其他的随机数都只出现了一次");
    }
}


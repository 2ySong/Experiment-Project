package exp2.finalization;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

/**
 * @Author: Song-zy
 * @Date: 2021/10/29 9:45
 * @Description:
 */
public class ProOne3 {
    @SuppressWarnings("all")
    public static void main(String[] args) {
        int[] nums = new int[100];
        for (int i = 0; i < nums.length; i++) {
            //Math.random()是令系统随机选取大于等于 0.0 且小于 1.0 的伪随机 double 值
            nums[i] = (int) (Math.random() * 999);//0~999之间的随机数赋值给数组元素
        }
        System.out.print("====随机数组====\n{");
        for (int i = 0; i < nums.length; i++) {
            if (i % 10 == 0 && i != 0) {
                System.out.println();
            }
            System.out.print(nums[i] + ",");
        }
        System.out.println("}");
        //将这100个随机数组装成一个字符串
        String str = null;
        for (Object o : nums) {
            str += o;
        }
        HashMap hashMap = new HashMap();
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < 10; j++) {
                if(str.charAt(i)==j+48){
                    if(hashMap.containsKey(str.charAt(i))){
                        hashMap.put(str.charAt(i),(int)hashMap.get(str.charAt(i))+1);
                        break;
                    }else{
                        hashMap.put(str.charAt(i),1);
                        break;
                    }
                }
            }
        }
        Set keySet = hashMap.keySet();
        Iterator it = keySet.iterator();
        while (it.hasNext()) {
            Object next =  it.next();
            System.out.println(next+"出现了"+hashMap.get(next)+"次");
        }
    }
}

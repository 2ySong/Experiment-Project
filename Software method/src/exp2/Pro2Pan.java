package exp2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;
import java.util.Map.Entry;

/**
 * @Author: Song-zy
 * @Date: 2021/11/5 8:17
 * @Description:
 */
public class Pro2Pan {
    public static void main(String[] args) throws Exception {
        //读文件
        try (BufferedReader br = new BufferedReader(new FileReader("E:\\Experiment-Project\\Software method\\src\\exp2\\word.txt"))) {
            HashMap<String, Integer> map = new HashMap();//建一个存放读入数据的集合
            String line = null;//每次读取一行
            while ((line = br.readLine()) != null) {//循环读入
                line = line.replace(',',' ');
                line = line.replace(';',' ');
                line = line.replace('.',' ');
                String[] split = line.split(" ");//切分
                for (String word : split) {//遍历字符串数组
                    if (word.length() != 0) {//判断对象不为空
                        if (map.containsKey(word)) {//判断集合中是否包括目标单词
                            map.put(word, map.get(word) + 1);//如果包括，value值+1，如果不包括，将新单词放入集合中
                        } else {
                            map.put(word, 1);
                        }
                    }
                }
            }
            Set<Entry<String, Integer>> entrySet = map.entrySet();//集合中的元素以k,v形式取出
            ArrayList<Entry<String, Integer>> list = new ArrayList<Entry<String, Integer>>(entrySet);//放入List集合中
            Collections.sort(list, new Comparator<Entry<String, Integer>>() {//进行降序排序
                @Override//重写比较器
                public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
                    return o2.getValue().compareTo(o1.getValue());
                }
            });
            System.out.println(list);//打印结果
        }catch (Exception e) {
            System.out.println("\033[31m" +"Error in reading file!");
        }
    }
}
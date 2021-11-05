package exp2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;

/**
 * @Author: Song-zy
 * @Date: 2021/11/5 8:26
 * @Description:
 */
public class Pro2_4 {
    public static void main(String[] args) {
        TreeMap<String, Integer> treeMap = new TreeMap<>();
        String str[] = null;
        try {
            File file = new File("/E:\\Experiment-Project\\Software method\\src\\exp2\\word.txt");
            if (file.isFile() && file.exists()) {
                InputStreamReader isr = new InputStreamReader(new FileInputStream(file), "utf-8");
                BufferedReader br = new BufferedReader(isr);
                String lineTxt = null;
                while ((lineTxt = br.readLine()) != null) {
                    lineTxt = lineTxt.replace(',', ' ');
                    lineTxt = lineTxt.replace(';', ' ');
                    lineTxt = lineTxt.replace(".", " ");
                    str = lineTxt.split(" ");
                    for (int i = 0; i < str.length; i++) {
                        if (treeMap.containsKey(str[i])) {
                            treeMap.put(str[i], (Integer) treeMap.get(str[i]) + 1);
                        } else {
                            treeMap.put(str[i], 1);
                        }
                    }
                    // treemap按照value 排序
                    List<Map.Entry<Integer, Integer>> list = new ArrayList(treeMap.entrySet());

                    // 然后通过比较器来实现排序
                    Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() {
                        // 降序排序
                        @Override
                        public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                            return o2.getValue().compareTo(o1.getValue());
                        }
                    });
                    Iterator iter = treeMap.keySet().iterator();// 得到树映射键集合的迭代器
                    Object key = null;
                    for (Map.Entry<Integer, Integer> e : list) {
                        System.out.println(e.getKey() + "出现了" + e.getValue() + "次;");
                        key = iter.next();
                    }
                }
                br.close();
            } else {
                System.out.println("\033[31m" + "Error: The file does not exist!");//字体颜色变红
            }
        } catch (Exception e) {
            System.out.println("\033[31m" + "Error in reading file!");
        }
    }
}

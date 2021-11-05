package exp2;

import java.io.*;
import java.util.*;

/**
 * @Author: Song-zy
 * @Date: 2021/10/29 8:16
 * @Description:
 */
public class ProgramSecond2 {
    public static void main(String[] args) {
        String filePath = "/E:\\Love me\\Software method\\src\\experiment2\\word.txt";
        String str = readTxt(filePath);
        char[] chs = str.toCharArray();
        Object num = null;
        TreeMap treeMap = new TreeMap();
        for (int i = 0; i < chs.length; i++) {
            for (int j = 0; j < 26; j++) {
                if (chs[i] == j + 65 || chs[i] == j + 97) {
                    if (treeMap.containsKey(chs[i])) {
                        num = treeMap.get(chs[i]);
                        treeMap.put(chs[i], (Integer) num + 1);
                    } else {
                        treeMap.put(chs[i], 1);
                    }
                }
            }
        }

        // treemap按照value 排序
        List<Map.Entry<Integer, Integer>> list = new ArrayList<Map.Entry<Integer, Integer>>(treeMap.entrySet());

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
            System.out.println(e.getKey() + "出现了" + e.getValue()+"次;");
            key = iter.next();
        }

    }

    //读取文件
    public static String readTxt(String filePath) {
        String str = "";
        try {
            File file = new File(filePath);
            if (file.isFile() && file.exists()) {
                InputStreamReader isr = new InputStreamReader(new FileInputStream(file), "utf-8");
                BufferedReader br = new BufferedReader(isr);
                String lineTxt = null;
                while ((lineTxt = br.readLine()) != null) {
                    str += lineTxt;
                }
                br.close();
            } else {
                System.out.println("文件不存在!");
            }
        } catch (Exception e) {
            System.out.println("文件读取错误!");
        }
        return str;
    }
}

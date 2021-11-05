import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Set;

/**
 * @Author: Song-zy
 * @Date: 2021/10/28 23:02
 * @Description:
 */
@SuppressWarnings("all")
public class ProgramSecond {
    public static void main(String[] args) {
        String filePath = "/E:\\Love me\\Software method\\src\\experiment2\\word.txt";
//        System.out.println();
        String str = readTxt(filePath);
        char[] chs = str.toCharArray();
        HashMap<Character, Integer> hashMap = new HashMap();
        for (int i = 0; i < chs.length; i++) {
            for (int j = 0; j < 26; j++) {
                if (chs[i] == j + 65 || chs[i] == j + 97) {
                    if (hashMap.get(chs[i]) == null) {
                        hashMap.put(chs[i], 1);
                    } else {
                        hashMap.put(chs[i], hashMap.get(chs[i]) + 1);
                    }
                }
            }
        }
        Set keySet = hashMap.keySet();
        for (Object o : keySet) {
            System.out.println(o + "出现了" + hashMap.get(o) + "次");
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

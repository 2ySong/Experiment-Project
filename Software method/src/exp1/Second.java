package exp1;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.util.Scanner;

/**
 * @Author: Song-zy
 * @Date: 2021/10/22 9:40
 * @Description:
 * 程序2：
 *      输入年份和月份(需要进行输入检查：年份是否大于1800且小于3000的整数，月份是1~12之间的整数)，输出该月份的日历。
 */
public class Second {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("请输入年份：");
            int year = scanner.nextInt();
            if (year < 1800 || year > 3000) {
                System.out.println("你输入的年份不在(1800~3000)范围内！！\n请重新输入！！！");
                continue;
            }
            System.out.print("请输入月份：");
            int month = scanner.nextInt();
            if (month < 1 || month > 12) {
                System.out.println("你输入的月份不在(1~12)范围内！！\n请重新输入！！！");
                continue;
            }
            DateDemo.calendar(year, month);
            break;
        }
    }
}

class DateDemo {
    static int k = 0;//全局变量，保存日期与星期对齐时，应该退后的格子数。

    //将日历封装
    public static void calendar(int year, int month) {
        //判断月份的天数
        int daysOfMonth = 0;
        if (month == 2) {
            if (year % 400 == 0 && (year % 4 == 0 || year % 100 != 0)) {
                //闰年的二月份是29天，平年的二月份是28天
                daysOfMonth = 29;
            } else {
                daysOfMonth = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysOfMonth = 30;//小月30天
        } else {
            daysOfMonth = 31;//大月31天
        }
        System.out.println(year + "年" + month + "月");
        System.out.println("日\t" + "一\t" + "二\t" + "三\t" + "四\t" + "五\t" + "六");
        for (int i = 0; i < daysOfMonth; i++) {
            LocalDate ldt = LocalDate.of(year, month, (i + 1));
            DayOfWeek dayOfWeek = ldt.getDayOfWeek();//获取每号对应的星期数

            if ((i + k) % 7 == 0 && i != 0) {
                System.out.println();
            }
            if (i == 0) {
                System.out.print(backspace(dayOfWeek));
            }
            System.out.print((i + 1) + "\t");
        }
    }

    //让日期对齐星期
    @SuppressWarnings("all")
    public static String backspace(DayOfWeek dayOfWeek) {
        String src = "";
        switch (dayOfWeek) {
            case MONDAY:
                k = 1;
                break;
            case TUESDAY:
                k = 2;
                break;
            case WEDNESDAY:
                k = 3;
                break;
            case THURSDAY:
                k = 4;
                break;
            case FRIDAY:
                k = 5;
                break;
            case SATURDAY:
                k = 6;
                break;
        }
        for (int i = 0; i < k; i++) {
            src += "\t";
        }
        return src;
    }
}
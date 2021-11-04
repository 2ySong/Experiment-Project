package exp2.finalization;

/**
 * @Author: Song-zy
 * @Date: 2021/10/29 9:40
 * @Description:
 */
public class ProThree {
    public static void main(String[] args) {
        Student u1 = new Undergraduate("001", "小明(本科)", 60, 89.22, 34);
        Student u2 = new Undergraduate("002", "康康(本科)", 60, 60, 59.88);
        Student g1 = new Graduate("003", "张三(研究生)", 78.9, 80.23, 90.34);
        pass(u1);
        pass(u2);
        pass(g1);
    }

    public static void pass(Student s) {
        if (s.isPass()) {
            System.out.println("学号为"+s.getId()+"的"+s.getName() + "通过了学位测试");
        } else {
            System.out.println("学号为"+s.getId()+"的"+s.getName() + "没有通过学位测试");
        }
    }
}

//学生类
class Student {
    private String name;
    private String id;
    private double c1;
    private double c2;
    private double c3;

    public Student(String id, String name, double c1, double c2, double c3) {
        this.name = name;
        this.id = id;
        this.c1 = c1;
        this.c2 = c2;
        this.c3 = c3;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public double getC1() {
        return c1;
    }

    public void setC1(double c1) {
        this.c1 = c1;
    }

    public double getC2() {
        return c2;
    }

    public void setC2(double c2) {
        this.c2 = c2;
    }

    public double getC3() {
        return c3;
    }

    public void setC3(double c3) {
        this.c3 = c3;
    }

    public boolean isPass() {
        return false;
    }

    public double avg() {
        return (c1 + c2 + c3) / 3;
    }

}

//本科生类
class Undergraduate extends Student {
    private final double PASS_SCORE = 60;

    public Undergraduate(String name, String id, double c1, double c2, double c3) {
        super(name, id, c1, c2, c3);
    }

    @Override
    public boolean isPass() {
        if (avg() >= PASS_SCORE) {
            return true;
        }
        return false;
    }
}

//研究生类
class Graduate extends Student {
    private final double PASS_SCORE = 80;

    public Graduate(String name, String id, double c1, double c2, double c3) {
        super(name, id, c1, c2, c3);
    }

    @Override
    public boolean isPass() {
        if (avg() >= PASS_SCORE) {
            return true;
        }
        return false;
    }
}

interface X {
    int a = 1;
}

interface Y {
    int a = 2;
}

public class helo implements X, Y {

    public static void main(String[] args) throws Exception {
        System.out.println(T.a);
    }
}

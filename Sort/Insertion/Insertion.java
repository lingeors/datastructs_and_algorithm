/**
 * Created by coder on 2/13/2017.
 * 这里我们使用了 《算法4》中的排序算法框架
 */
public class Insertion {
    public static void main(String[] args) {
        int count = 10;
        int max = 10;
        Comparable<Integer> a[] = new Integer[count];
        createRandom(a, count, max);
        show(a);
        System.out.println("");
        sort(a);
        show(a);
    }

    public static void sort(Comparable[] a) {
        for (int i = 0; i < a.length-1; i++) {
            Comparable tmp = a[i+1];
            int j = i+1;
            for (; j > 0; j--) {
                if (less(tmp, a[j-1])) a[j] = a[j-1];
                else break;
            }
            a[j] = tmp;
        }
    }

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    private static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }

    private static void swap(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void createRandom(Comparable[] a, int count, int max) {
        for (int i = 0; i < count; i++) {
            a[i] = (int)Math.round(Math.random()*max);
        }
    }
}

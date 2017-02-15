/**
 * Created by coder on 2/13/2017.
*  这里我们使用了《算法4》中的排序算法框架
 */
public class Merge {
    public static void main(String[] args) {
        int count = 10;
        int max = 100;
        Comparable<Integer> a[] = new Integer[count];
        createRandom(a, count, max);
        show(a);
        System.out.println("");
        sort(a);
        assert isSorted(a);
        show(a);
    }

    public static void sort(Comparable[] a) {
        // 我们在这里设置一个数组，避免在递归期间生成多个数组
        Comparable tmp[] = new Comparable[a.length];
        sort(tmp, a, 0, a.length-1);
    }

    public static void sort(Comparable[] tmp, Comparable[] a, int lo, int hi) {
        if (lo >= hi) return;
        int mid = (lo+hi) / 2;
        sort(tmp, a, lo, mid);
        sort(tmp, a, mid+1, hi);
        if (less(a[mid+1], a[mid]))
            merge(tmp, a, lo, mid, hi);
    }

    /**
     * 合并两个数组。这里我们使用 lo，min，hi 三个索引指针
     * 将一个数组标记为两部分来表示两个数组
     * @param tmp  合并时使用的缓存数组
     * @param a    待操作数组
     * @param lo   第一个子数组的第一个元素
     * @param mid  第一个子数组的最后一个元素
     * @param hi   第二个子数组的最后一个元素
     */
    public static void merge(Comparable[] tmp, Comparable[] a, int lo, int mid, int hi) {
        int i = lo;
        int j = mid + 1;
        int index = lo;
        while (i <= mid && j <= hi) {
            if (less(a[i], a[j])) {
                tmp[index++] = a[i++];
            } else {
                tmp[index++] = a[j++];
            }
        }
        while (i <= mid) tmp[index++] = a[i++];
        while (j <= hi) tmp[index++] = a[j++];
        // 部分排序需要重新写回到a数组中，因为这部分后续还会被用到
        index = lo;
        while (lo <= hi) {
            a[lo++] = tmp[index++];
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

    public static boolean isSorted(Comparable[] a) {
        for (int i = 1; i < a.length; i++) {
            if (less(a[i], a[i-1])) return false;
        }
        return true;
    }
}

import java.util.*;
/**
 * Created by coder on 2/19/2017.
 */
public class Prime {
    public static void main(String[] args) {
        for (int i = 1; i < 50; i++) {
            if (isPrime2(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println("");
        for (int i = 1; i < 50; i++) {
            if (isPrime1(i)) {
                System.out.print(i + " ");
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 2; i <= 50; i++) {
            list.add(i);
        }
        System.out.println("");
        primeList(list);
        for (Integer i :
                list) {
            System.out.print(i + " ");
        }
    }

    private static boolean isPrime1(int nr) {
        for (int i = 2; i < nr; i++) {
            if (nr % i == 0) return false;
        }
        return true;
    }

    private static boolean isPrime2(int nr) {
        for (int i = 2; i*i <= nr; i++) {
            if (nr % i == 0) return false;
        }
        return true;
    }

    private static void primeList(List<Integer> nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums.get(i)*nums.get(i) <= nums.get(nums.size()-1)) {
                for (int j = i+1; j < nums.size(); j++) {
                    if (nums.get(j) % nums.get(i) == 0) nums.remove(j);
                }
            } else {
                return ;
            }
        }
    }


}



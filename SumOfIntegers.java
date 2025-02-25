import java.util.List;
import java.util.ArrayList;

public class SumOfIntegers {
    public static void main(String[] args) {
        List<Integer> integers = new ArrayList<>();
        integers.add(Integer.parseInt("10"));
        integers.add(Integer.parseInt("20"));
        integers.add(Integer.parseInt("30"));

        int sum = calculateSum(integers);
        System.out.println("Sum: " + sum);
    }

    public static int calculateSum(List<Integer> integers) {
        int sum = 0;
        for (Integer num : integers) {
            sum += num; // Autoboxing and unboxing
        }
        return sum;
    }
}

import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        array_example();
        System.out.println("\n-------------\n");
        array_list_example();
        System.out.println("\n-------------\n");
        resizable_array_example();
    }

    private static void array_example() {

        int[] numbersArray = {2, 3, 5, 7};
        System.out.println("third element: " + numbersArray[3]);
        System.out.println("length of array: " + numbersArray.length);

        numbersArray[3] = 11;
        System.out.println("new third element: " + numbersArray[3]);

        try {
            numbersArray[4] = 13; // error (exceeded size of the array)
        } catch(ArrayIndexOutOfBoundsException e) {
            System.err.println("length max array is: "+ numbersArray.length);
        }

    }

    private static void array_list_example() {

        final var __ = " ; size: ";
        var numbersList = new ArrayList<Integer>();

        numbersList.add(2);
        numbersList.add(3);
        numbersList.add(5);
        numbersList.add(7);
        System.out.println(numbersList+__+numbersList.size());
        
        numbersList.add(11);// no error (auto resize)
        System.out.println(numbersList+__+numbersList.size());

        numbersList.set(2, null);
        numbersList.remove(4);
        System.out.println(numbersList+__+numbersList.size());

    }

    private static void resizable_array_example() {

        final var __ = " ; size: ";
        var numbersList = new ArrayList<Integer>(12);

        numbersList.addAll(Arrays.asList(
            2,3,5,7,11,13,17,19,23,29
        ));
        System.out.println(numbersList+__+numbersList.size());

        numbersList.addAll(Arrays.asList(
            31,37,41,43,47
        ));
        System.out.println(numbersList+__+numbersList.size());

    }

}
public class RandomProblem {
    
    // answer is -2147483648 after cheching Math.abs source code it says
    // Note that if the argument is equal to the value of Integer.MIN_VALUE,
    // the most negative representable int value, the result is that same value,
    // which is negative. 

    public static int bucketFromRandom(int randomNumber) {
        int a[] = new int[10];
        
        for (int i = 0; i < a.length; i++)
            a[i] = i * randomNumber;
        
        int index = Math.abs(randomNumber) % a.length;
        return a[index];
    }

    public static void main(String[] args) {
        bucketFromRandom(Integer.MIN_VALUE);
    }
}

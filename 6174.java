import java.util.Arrays;

class HelloWorld {
    public static void main(String[] args) {
        int [] counts = new int [8];
        // calculate(6147);
        for(int i = 1000 ; i <= 9999 ; i++){
            
            if(i == 1111 || i == 2222 || i == 3333 || i == 4444 || i == 5555 || i == 6666 || i == 7777 || i == 8888 || i == 9999 ) continue;
            
            int curr = i;
            int count = 0;
            while(curr != 6174){
                curr = calculate(curr);
                count++;
            }
            
            System.out.println("For the number " + i + 
            " we did the process " + count + " times");

			counts[count]++;
            
        }

		System.out.println("Final Counts: ");

		for(int i = 0 ; i < counts.length ; i++){
			System.out.print(i + " = " + counts[i] + ", ");
		}
		

		int sum = 0;

		for(int i : counts) sum += i;

		System.out.println();
		System.out.println(sum);
    }
    
    public static int calculate(int x){
        
        int [] ascending = new int [4];
        int [] descending = new int [4];
        
        for(int i = 0 ; i < 4 ; i++){
            descending[i] = x % 10;
            x = x / 10;
        }
        
        Arrays.sort(descending);
        
        for(int i = 0 ; i < 4 ; i++){
            ascending[3-i] = descending[i];
        }
        
        int toReturn = 0;
        int [] intermediaryArray = new int [4];
        
        for(int i = 0 ; i < 4 ; i++){
            intermediaryArray[i] = ascending[i] - descending[i];
            
            if(intermediaryArray[i] < 0){
                intermediaryArray[i] += 10;
                intermediaryArray[i-1]--;
            }
            
        }
        
        for(int i : intermediaryArray){
            toReturn *= 10;
            toReturn += i;
        }
        
        return toReturn;
        
    }
}
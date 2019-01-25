import java.util.HashMap;
import java.util.Map;

public class twoSum {
    public static void main(String[] args){
        int nums[] = {1,2,3,4,5,6,7},target = 11;

        int[] result = twosum(nums, target);

        System.out.println("Hello World!" + result[0] + result[1]);
    }

    public static int[] twosum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            int content = target - nums[i];
            if(map.containsKey(content)) {
                return new int[] {map.get(content), i};
            }
            map.put(nums[i], i);
        }
        
        throw new IllegalArgumentException("No two sum solution");
    } 
}
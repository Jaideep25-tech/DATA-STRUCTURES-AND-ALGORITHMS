package searchingAndSorting;

public class AllocateBooks {
	// 25 : Book Allocation Problem
	
	public static int findPages(int[]a,int n,int m)
    {
		// edge cases
		if (a.length < m) return -1;
		
		int start = -1,end = 0, res=-1;
		
		for (int i=0 ; i<n ; i++) {
		    start = Math.max(a[i],start);
		    end += a[i];
		}
		
		if (a.length == m) return start;
		
		while (start <= end) {
			int mid = start + ((end-start)>>1);
			
			if (isValid(a,n,m,mid) == true) {
				res = mid;
				end = mid-1;
			}
			else 
				start = mid+1;	
		}
        return res;
    }
	
	private static boolean isValid(int[] a, int n, int m, int max) {
		int student=1, sum=0;
		
		for (int i=0; i<n; i++) {
			sum += a[i];
			
			if (sum > max) {
				student++;
				sum = a[i];
			}
			if (student > m) return false;
		}
		
		return true;
	}

	public static void main(String[] args) {
		int[] arr = {12,34,67,90};
		System.out.println(findPages(arr, arr.length, 2));
	}

}

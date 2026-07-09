class Solution {
    public int calPoints(String[] operations) {
        int l=operations.length;
        int[] arr = new int[l];
        int j=0;
        int s=0;
        for(int i=0;i<l;i++){
            if(operations[i].equals("C")){
                j--;
            }
            else if(operations[i].equals("D")){
                arr[j]=(2*arr[j-1]);
                j++;
            }
            else if(operations[i].equals("+")){
                arr[j]=(arr[j-2]+arr[j-1]);
                j++;
            }
            else{
                arr[j]=Integer.parseInt(operations[i]);
                j++;
            }
        }
        for(int k=0;k<j;k++){
            s=s+arr[k];
        }
        return s;
    }
}
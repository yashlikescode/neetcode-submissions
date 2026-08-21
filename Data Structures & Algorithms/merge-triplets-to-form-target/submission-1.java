class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int[] tracker = new int[triplets.length];
        Arrays.fill(tracker,1);


        int ind = 0;
        int a = triplets[0][0];
        int b = triplets[0][1];
        int c = triplets[0][2];


        for(int i= 0; i < tracker.length; i++){
            if(triplets[i][0] == target[0] && triplets[i][1] == target[1] && triplets[i][2] == target[2]) {
                return true;
            }
            if(triplets[i][0] > target[0] ||
               triplets[i][1] > target[1] ||
                triplets[i][2] > target[2] ||
                (triplets[i][0]!=target[0]&&triplets[i][1]!=target[1]&&triplets[i][2] > target[2])
                ){
                    tracker[i]=0;
                }
                else if(ind == 0){
                    ind = 1;
                    a = triplets[i][0];
                    b = triplets[i][1];
                    c = triplets[i][2];
                }
        }

        for(int i= 0; i < tracker.length; i++){
            if(tracker[i] > 0){
                a = Math.max(a,triplets[i][0]);
                b = Math.max(b,triplets[i][1]);
                c = Math.max(c,triplets[i][2]);
            }
        }
        int[] finalRes = {a,b,c};
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        
        return Arrays.equals(finalRes,target);
    }
}

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        int ind = 0;
        HashSet<Character> set = new HashSet<>();
        for(int i = 0; i < s.length(); i++){
            if(set.contains(s.charAt(i))){
                for(int j = ind; j< i; j++){
                    set.remove(s.charAt(j));
                    if(s.charAt(j) == s.charAt(i)){
                        ind = j+1;
                        break;
                    }
                }
                set.add(s.charAt(i));
                res = Math.max(set.size(),res);
            } else {
                set.add(s.charAt(i));
                res = Math.max(set.size(),res);
            }
        }
        return res;
    }
}

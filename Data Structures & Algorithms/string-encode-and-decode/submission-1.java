class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for(String s : strs){
            sb.append(s.length()).append('#').append(s); 
        }
        return sb.toString(); //  5#Hello5#World
    }

    public List<String> decode(String str) {
        List<String> decoded = new ArrayList<>();
         int i = 0;

         while( i < str.length()){
            int j = str.indexOf('#', i); // index if # : 1
            int len = Integer.parseInt(str.substring(i,j)); // extract the value : 5

            // extract string of given len
            decoded.add(str.substring(j + 1, j + 1 + len)); // ['Hello']

            // advaance pointe to the nex block
            i = j + 1 + len;
         }

         return decoded;
    }
}

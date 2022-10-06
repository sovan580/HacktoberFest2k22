class TimeMap {
    
    HashMap<String,String> hm;
    public TimeMap() {
        hm = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        String newKey = key + " " + timestamp;   // String which has both key and timestamp
        hm.put(newKey, value);                   // this newKey has been put in the map
    }
    
    public String get(String key, int timestamp) {
        // in this function also we merge the key and timestamp and check this in the map
        // we have used a while loop to return the value the the previous timestamp that exists in the map
        while(timestamp > 0){
            String chk = key + " " + timestamp;
            if(hm.containsKey(chk)){
                return hm.get(chk);
            }
            timestamp--;
        }
        return "";  
    }
}

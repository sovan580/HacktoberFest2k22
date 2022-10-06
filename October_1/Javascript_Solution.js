var numDecodings = function(s) {    
    let map = {};
    let count = { count: 0 };
    
    process(s, count, map);
    
    return count.count;
};

function process(current, count, map) {
    if (current[0] === '0') {
        return count.count;
    }
    
    if (map[current]) {
        count.count += map[current];
        return map[current];
    }
    
    if (!current.length) {
        count.count += 1;
        return count.count;
    }
    
    let c1 = process(current.slice(1), count, map);
    map[current.slice(1)] = c1;

    if (current.length >= 2 && +current.slice(0, 2) <= 26) {
        let c2 = process(current.slice(2), count, map);
        map[current.slice(2)] = c2;
    }
    
    return count.count;
}

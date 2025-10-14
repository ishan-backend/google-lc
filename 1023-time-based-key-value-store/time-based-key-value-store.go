type Pair struct {
	timestamp int
	value     string
}

type TimeMap struct {
	mp map[string][]Pair
}

// Constructor initializes a new TimeMap
func Constructor() TimeMap {
	return TimeMap{
		mp: make(map[string][]Pair),
	}
}

// Set stores the key-value pair with its timestamp
func (tm *TimeMap) Set(key string, value string, timestamp int) {
	tm.mp[key] = append(tm.mp[key], Pair{timestamp, value})
}

// Get retrieves the value with the largest timestamp <= given timestamp
func (tm *TimeMap) Get(key string, timestamp int) string {
	pairs, exists := tm.mp[key]
	if !exists {
		return ""
	}

	lo, hi := 0, len(pairs)-1
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if pairs[mid].timestamp == timestamp {
			return pairs[mid].value
		} else if pairs[mid].timestamp < timestamp {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}

	if hi >= 0 {
		return pairs[hi].value
	}
	return ""
}
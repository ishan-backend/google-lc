package main

type TsCount struct {
	Ts  int
	Cnt int
}

type HitCounter struct {
	Counters []TsCount
}

func Constructor() HitCounter {
	return HitCounter{
		Counters: make([]TsCount, 0),
	}
}

func (this *HitCounter) Hit(timestamp int) {
	n := len(this.Counters)
	if n > 0 && this.Counters[n-1].Ts == timestamp {
		this.Counters[n-1].Cnt++
	} else {
		this.Counters = append(this.Counters, TsCount{
			Ts:  timestamp,
			Cnt: 1,
		})
	}
}

const FIVE_MINS = 300

func (this *HitCounter) GetHits(timestamp int) int {
	start := timestamp - FIVE_MINS + 1
	counters := this.Counters
	n := len(counters)

	// Binary search for first index with Ts >= start
	left, right := 0, n
	for left < right {
		mid := (left + right) / 2
		if counters[mid].Ts < start {
			left = mid + 1
		} else {
			right = mid
		}
	}

	// Sum counts from left to end
	total := 0
	for i := left; i < n; i++ {
		total += counters[i].Cnt
	}

	return total
}
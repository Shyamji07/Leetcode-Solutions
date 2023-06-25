/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function(gain) {
	let [max, currentAltitude] = [0, 0];

	for (let i = 0; i < gain.length; i++) {
		currentAltitude = gain[i] + currentAltitude;
		if (currentAltitude > max) max = currentAltitude;
	}

	return max;
};

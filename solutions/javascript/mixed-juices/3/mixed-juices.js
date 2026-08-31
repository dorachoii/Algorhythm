
export function timeToMixJuice(name) {
  switch (name) {
    case 'Pure Strawberry Joy':
      return 0.5;
    case 'Energizer':
    case 'Green Garden':
      return 1.5;

    case 'Tropical Island':
      return 3;

    case 'All or Nothing':
      return 5;

    default:
      return 2.5;

  }
}

/**
 * Calculates the number of limes that need to be cut
 * to reach a certain supply.
 *
 * @param {number} wedgesNeeded
 * @param {string[]} limes
 * @returns {number} number of limes cut
 */
export function limesToCut(wedgesNeeded, limes) {
  let cnt = 0;

  while (wedgesNeeded > 0 && cnt < limes.length) {
    const size = limes[cnt];

    if (size === 'small') { wedgesNeeded -= 6; }
    else if (size === 'medium') { wedgesNeeded -= 8; }
    else if (size === 'large') { wedgesNeeded -= 10; }

    cnt++;
  }
  return cnt;
}

/**
 * Determines which juices still need to be prepared after the end of the shift.
 *
 * @param {number} timeLeft
 * @param {string[]} orders
 * @returns {string[]} remaining orders after the time is up
 */
export function remainingOrders(timeLeft, orders) {
  let idx = 0;

  while (timeLeft > 0 && idx < orders.length) {
      timeLeft -= timeToMixJuice(orders[idx]);
      idx++;
    }
  
  return orders.slice(idx);
}

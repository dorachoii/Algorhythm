
export function dayRate(ratePerHour) {
  return ratePerHour * 8;
}


export function daysInBudget(budget, ratePerHour) {
  return Math.floor(budget / (ratePerHour * 8));
}


export function priceWithMonthlyDiscount(ratePerHour, numDays, discount) {
  let a = numDays % 22;
  let b = Math.floor(numDays / 22);

  return Math.ceil((b * ratePerHour * 8 * 22) * (1 - discount) + a * ratePerHour * 8);
}

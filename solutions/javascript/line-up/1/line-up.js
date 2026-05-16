export const format = (name, order) => {

  let lastDigit = order % 10;
  let lastTwoDigit = order % 100;
  let suffix = 'th';

  if (lastDigit == 1 && lastTwoDigit != 11) {
    suffix = 'st';
  } else if (lastDigit == 2 && lastTwoDigit != 12) {
    suffix = 'nd';
  } else if (lastDigit == 3 && lastTwoDigit != 13) {
    suffix = 'rd';
  } else {
    suffix = 'th';
  }

  return `${name}, you are the ${order}${suffix} customer we serve today. Thank you!`;
};

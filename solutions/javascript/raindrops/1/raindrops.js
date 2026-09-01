//
// This is only a SKELETON file for the 'Raindrops' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const convert = (number) => {
  let answer = '';

  if (number % 3 === 0) {
    answer += "Pling";
  }

  if (number % 5 === 0) {
    answer += "Plang";
  }

  if (number % 7 === 0) {
    answer += "Plong";
  }

  if (answer === '') {
    answer = `${number}`;
  }

  return answer;
};



export function needsLicense(kind) {
  return kind == 'car' || kind == 'truck';
}

export function chooseVehicle(option1, option2) {
  let answer;
  if(option1 < option2){
    answer = option1;
    
  }else{
    answer = option2;
  }
  return answer + ' is clearly the better choice.';
  
}

export function calculateResellPrice(originalPrice, age) {
  if(age < 3){
    return originalPrice *0.8;
  }
  else if(age <= 10){
    return originalPrice * 0.7;
  }
  else{
    return originalPrice * 0.5;
  }
}

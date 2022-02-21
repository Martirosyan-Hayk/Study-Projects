import * as bcrypt from 'bcrypt';

export function generateHash(password: string): string {
  return bcrypt.hashSync(password, 10);
}

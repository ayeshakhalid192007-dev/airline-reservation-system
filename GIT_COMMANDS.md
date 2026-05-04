# Git Commands to Commit and Push Changes

## Quick Method - Run the Script

```bash
cd /home/ayeshakhalid/OOP-PROJECT
chmod +x commit_and_push.sh
./commit_and_push.sh
```

---

## Manual Method - Step by Step

If you prefer to run commands manually:

### 1. Check Status
```bash
cd /home/ayeshakhalid/OOP-PROJECT
git status
```

### 2. Add Modified Files
```bash
git add src/domain/Airline.h
git add src/domain/Flight.h
git add src/services/helpers.cpp
git add FIXES_APPLIED.md
git add QUICK_REFERENCE.md
git add RUNNING_EXECUTABLES.md
git add airline.desktop
git add airline
git add airline.exe
```

### 3. Create Commit
```bash
git commit -m "fix: implement complete booking, cancellation, and viewing functionality

This commit fixes all major issues with the booking system:

- Fix booking not being saved to flight
- Fix view booking details not working  
- Fix cancel booking not working
- Fix display flight manifest not working

Technical changes:
- Added friend function declarations in Airline.h and Flight.h
- Rewrote 4 helper functions in helpers.cpp
- Fixed method name from getAmount() to getAmountPaid()

Documentation added:
- FIXES_APPLIED.md - Technical details
- QUICK_REFERENCE.md - User guide
- RUNNING_EXECUTABLES.md - How to run

Executables updated for Linux and Windows.

Co-Authored-By: Claude Sonnet 4 <noreply@anthropic.com>"
```

### 4. Push to GitHub
```bash
git push origin master
```

---

## Verify Push

After pushing, verify on GitHub:
```bash
git log -1
```

This will show your latest commit.

---

## If Push Fails

### Check Remote URL
```bash
git remote -v
```

### Check Branch
```bash
git branch
```

### Force Push (Use with Caution)
```bash
git push -f origin master
```

---

## Files Changed in This Commit

- `src/domain/Airline.h` - Added friend declarations
- `src/domain/Flight.h` - Added forward declaration and friend
- `src/services/helpers.cpp` - Rewrote 4 functions
- `FIXES_APPLIED.md` - New documentation
- `QUICK_REFERENCE.md` - New user guide
- `RUNNING_EXECUTABLES.md` - New executable guide
- `airline.desktop` - New Linux launcher
- `airline` - Updated Linux executable
- `airline.exe` - Updated Windows executable

---

## Summary

**Total Files Modified:** 3
**Total Files Added:** 6
**Lines Changed:** ~200 lines

All changes fix the booking, viewing, and cancellation functionality.

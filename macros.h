/*
Copyright(C) 2017 Edward Xie

This program is free software:you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation,either version 3 of the License,or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not,see <https://www.gnu.org/licenses/>.
*/
#ifndef MACROS_H
#define MACROS_H
#ifdef _WINDOWS
#ifdef MACROS_EXPORTS
#define MACROS_API __declspec(dllexport)
#else
#define MACROS_API __declspec(dllimport)
#endif
#include <Windows.h>
#include <string>
#include <memory>
#include <vector>
#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4a
#define VK_K 0x4b
#define VK_L 0x4c
#define VK_M 0x4d
#define VK_N 0x4e
#define VK_O 0x4f
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5a
#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39

#define ME_MOUSE1 0
#define ME_MOUSE2 1
#define ME_MOUSE3 2
namespace macro_commands {
	/*
		Converts a char to a virtual key code
		If there is no code, 0 is returned
	*/
	constexpr WORD MACROS_API char_to_vk(char const c);
	/*
		Returns the "lowercase" version of any character
	*/
	constexpr char MACROS_API unshift(char const c);
	/*
		Turns a string into a vector of key inputs
	*/
	std::vector<INPUT> MACROS_API string_to_inputs(std::string const& str);
	/*
		Turns a code combo (chord) into a vector of key inputs
	*/
	std::vector<INPUT> MACROS_API combo_to_inputs(std::vector<WORD> const&);
	/*
		Injects a vector of inputs into the System
	*/
	int MACROS_API inject_inputs(std::vector<INPUT>& inputs);
	/*
		Returns whether the character can be typed with one key press
	*/
	constexpr bool MACROS_API is_key(char const c);
	/*
		Returns whether a window (e.g. L"IEFrame") is open
	*/
	bool MACROS_API is_window_open(wchar_t* const name);
	/*
		Returns whether a program (e.g. L"iexplore.exe") is on
		CURRENTLY NOT IMPLEMENTED, RETURNS FALSE
	*/
	bool MACROS_API is_program_on(wchar_t* const name);
	/*
		Releases a given key by key code
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API release_key(WORD const code);
	/*
		Releases a given key by character
		Returns 0 on success
		Returns 1 on failure to send iput
		Returns 2 on non-existent key
	*/
	int MACROS_API release_key(char const c);
	/*
		Presses a given key by key code
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API press_key(WORD const code);
	/*
		Presses a given key by character
		Returns 0 on success
		Returns 1 on failure to send iput
		Returns 2 on non-existent key
	*/
	int MACROS_API press_key(char const c);
	/*
		Taps a given key by key code
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API tap_key(WORD const code);
	/*
		Taps a given key by character
		Returns 0 on success
		Returns 1 on failure to send iput
		Returns 2 on non-existent key
	*/
	int MACROS_API tap_key(char const c);
	/*
		Types out a string
		Returns 0 on success
		Returns 1 on failure
		Returns 2 on invalid character
	*/
	int MACROS_API type_string(std::string const& str);
	/*
		Presses a key by key code while holding ctrl
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API ctrl_combo(WORD const code);
	/*
		Presses a key by key code while holding ctrl
		Returns 0 on success
		Returns 1 on failure to send input
		Returns 2 on non-existent key
	*/
	int MACROS_API ctrl_combo(char const c);
	/*
		Taps the keys as a combo
		e.g. {VK_CONTROL,VK_ALT,VK_C} => Ctrl+Alt+c
	*/
	int MACROS_API combo(std::vector<WORD> const& combo);
	/*
		Moves the mouse to absolute x y
		(0,0) IS NOT A VALID COORDINATE
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API move_mouse(ULONG const x,ULONG const y);
	/*
		Moves the mouse a relative x y
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API translate_mouse(LONG const x,LONG const y);
	/*
		Taps a button on the mouse. Buttons are in ME_ definitions
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API tap_mouse_button(unsigned int const button);
	/*
		Presses down a button on the mouse. Buttons are in ME_ definitions
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API press_mouse_button(unsigned int const button);
	/*
		Releases a button on the mouse. Buttons are in ME_ definitions
		Returns 0 on success
		Returns 1 on failure to send input
	*/
	int MACROS_API release_mouse_button(unsigned int const button);
	/*
		Returns the clipboard data as a string
		Throws exception on failure to access clipboard
	*/
	std::string MACROS_API get_clipboard_string();
	/*
		Puts a string on the clipboard
		Returns 0 on success
		Returns 1 on failure to set clipboard data
		Returns 2 on failure to open clipboard
		Returns 3 on failure to clear clipboard
	*/
	int MACROS_API set_clipboard_string(std::string const& str);

	/*
		Class used to run a program with parameters
	*/
	class MACROS_API Process {
	private:
		wchar_t*				prog_name;
		wchar_t*				params;
		PROCESS_INFORMATION*	pi;
	public:
		//Process();
		/*
			Creates a process to execute a program with no parameters
		*/
		explicit Process(std::wstring const& prog_name);
		/*
			Creates a process to execute a program with given parameters
		*/
		explicit Process(std::wstring const& prog_name,std::wstring const& params);

		Process(Process const& other);
		Process(Process&& other);

		Process& operator=(Process const& other);
		Process& operator=(Process&& other);
		~Process();

		bool operator==(Process const& other) const;
		/*
			Starts a program
			Returns 0 on success
			Returns 1 on failure
		*/
		int start(STARTUPINFO& si=STARTUPINFO{sizeof(STARTUPINFO)},DWORD flags=0) const;
		DWORD get_process_id() const;
		DWORD get_thread_id() const;
		void set_parameters(std::wstring const& params);
		wchar_t const* get_parameters() const;
		void set_program(std::wstring const& prog_name);
		wchar_t const* get_program() const;
		void wait_close(DWORD timeout=ULONG_MAX) const;
	};

	class MACROS_API Command {
	protected:
		Command()=default;
	public:
		virtual ~Command()=default;
		virtual int execute()=0;
	};
	class MACROS_API MultiCommand:public Command{
	protected:
		std::vector<INPUT> inputs;
		MultiCommand()=default;
	public:
		virtual ~MultiCommand()=default;
		int execute();
	};
	class MACROS_API DoubleCommand:public Command {
	protected:
		INPUT inputs[2];
		DoubleCommand()=default;
	public:
		virtual ~DoubleCommand()=default;
		int execute();
	};
	class MACROS_API SingleCommand:public Command {
	protected:
		INPUT input;
		SingleCommand()=default;
	public:
		virtual ~SingleCommand()=default;
		int execute();
	};

	class MACROS_API TypeCommand:public MultiCommand {
	public:
		TypeCommand(std::string const&);
		~TypeCommand()=default;
	};
	class MACROS_API ComboCommand:public MultiCommand {
	public:
		ComboCommand(std::vector<WORD> const&);
		~ComboCommand()=default;
	};
	class MACROS_API PressKeyCommand:public SingleCommand {
	public:
		PressKeyCommand(WORD code);
		PressKeyCommand(char key);
		~PressKeyCommand()=default;
	};
	class MACROS_API ReleaseKeyCommand:public SingleCommand {
	public:
		ReleaseKeyCommand(WORD code);
		ReleaseKeyCommand(char key);
		~ReleaseKeyCommand()=default;
	};
	class MACROS_API TapKeyCommand:public DoubleCommand {
	public:
		TapKeyCommand(WORD code);
		TapKeyCommand(char key);
		~TapKeyCommand()=default;
	};
	class MACROS_API TapMouseCommand:public DoubleCommand {
	public:
		TapMouseCommand(unsigned int button);
		~TapMouseCommand()=default;
	};
	class MACROS_API PressMouseCommand:public SingleCommand {
	public:
		PressMouseCommand(unsigned int button);
		~PressMouseCommand()=default;
	};
	class MACROS_API ReleaseMouseCommand:public SingleCommand {
	public:
		ReleaseMouseCommand(unsigned int button);
		~ReleaseMouseCommand()=default;
	};
	class MACROS_API MoveMouseCommand:public SingleCommand {
	public:
		MoveMouseCommand(ULONG x,ULONG y);
		~MoveMouseCommand()=default;
	};
	class MACROS_API TranslateMouseCommand:public SingleCommand {
	public:
		TranslateMouseCommand(LONG dx,LONG dy);
		~TranslateMouseCommand()=default;
	};
	class MACROS_API SleepCommand:public Command {
	private:
		DWORD time;
	public:
		SleepCommand(DWORD const time);
		~SleepCommand()=default;
		int execute();
	};

	void MACROS_API loop_until_key_pressed(std::vector<std::unique_ptr<Command>> const& commands,WORD esc_code=VK_ESCAPE);

}

#endif //_WINDOWS
#endif //MACROS_H